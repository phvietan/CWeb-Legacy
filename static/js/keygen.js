storage = new StorageHandler();

function createKeys() {
  const prfL = forge.random.getBytesSync(32);
  const prfR = forge.random.getBytesSync(32);
  const aesKey = forge.random.getBytesSync(32);
  
  const keys = forge.util.encode64(prfL + prfR + aesKey);
  storage.setItem('keys', keys);
}

function checkKeys() {
  const keys = storage.getItem('keys');
  if (keys === null || keys === undefined || forge.util.decode64(keys).length != 32*3) createKeys();
}

checkKeys();

function getPrf(key, word) {
  const hmac = forge.hmac.create();
  hmac.start('sha256', key);
  hmac.update(word);
  return hmac.digest().data;
}

function get00(aesKey, prfL, prfR, word) {
  let trapdoor = getPrf(aesKey, word);
  for (let i = 0; i < 32; ++i)
    trapdoor = getPrf(prfL, trapdoor);
  return forge.util.bytesToHex(trapdoor);
}

console.log(get00(aesKey, prfL, prfR, word));