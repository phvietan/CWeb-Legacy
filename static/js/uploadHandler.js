function readBlob(opt_startByte, opt_stopByte) {

    var files = document.getElementById('fileinput').files;
    if (!files.length) {
        alert('Please select a file!');
        return;
    }

    var file = files[0];
    var start = parseInt(opt_startByte) || 0;
    var stop = parseInt(opt_stopByte) || file.size - 1;

    var reader = new FileReader();

    // If we use onloadend, we need to check the readyState.
    reader.onloadend = function(evt) {
        if (evt.target.readyState == FileReader.DONE) { // DONE == 2
            window.bits.push(aesEncryptor.process(evt.target.result));
        }
    };

    var blob = file.slice(start, stop + 1);
    reader.readAsBinaryString(blob);
}

function handling(evt) {

    // INITIALIZE PROGRESSIVE ENCRYPTION
    var key = CryptoJS.enc.Hex.parse(document.getElementById('pass').value);
    var iv = CryptoJS.lib.WordArray.random(128 / 8);
    window.bits = [];
    window.aesEncryptor = CryptoJS.algo.AES.createEncryptor(key, {iv: iv});

    // LOOP THROUGH BYTES AND PROGRESSIVELY ENCRYPT
    var startByte = 0;
    var endByte = 0;
    while(startByte < document.querySelector('input[type=file]').files[0].size - 1){
        endByte = startByte + 1000000;
        readBlob(startByte, endByte);
        startByte = endByte;
    }

    // FINALIZE ENCRYPTION AND UPLOAD
    var encrypted = aesEncryptor.finalize();
    encrypted = encodeURIComponent(encrypted);
    var filename = document.getElementById('fileinput').value;
    var file_type = document.getElementById('fileinput').files[0].type;
    var url = 'data=' + encrypted + '&filename=' + filename + '&filetype=' + file_type;
    $.ajax({
        url: 'myphpscript.php',
        type: 'POST',
        data: url
    }).success(function(data){
        // Display encrypted data
        document.getElementById('status').innerHTML = 'Upload Complete.';
    });
    alert(encrypted);

}