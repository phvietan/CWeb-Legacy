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

const keys = forge.util.decode64(storage.getItem('keys'));

const prfL = keys.slice(0, 32);
const prfR = keys.slice(32, 64);
const aesKey = keys.slice(64, 96);

console.log(prfL);
console.log(forge.util.bytesToHex(prfL));
console.log(prfL.length);

console.log(aesKey);
console.log(forge.util.bytesToHex(aesKey));
console.log(aesKey.length);

function getPrf(key, word) {
  const hmac = forge.hmac.create();
  hmac.start('sha256', key);
  hmac.update(word);
  return hmac.digest().data;
}

const word = 'hello world';

function get00(aesKey, prfL, prfR, word) {
  let trapdoor = getPrf(aesKey, word);
  for (let i = 0; i < 32; ++i)
    trapdoor = getPrf(prfL, trapdoor);
  return forge.util.bytesToHex(trapdoor);
}

console.log(get00(aesKey, prfL, prfR, word));