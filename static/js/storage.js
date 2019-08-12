function StorageHandler() {}

StorageHandler.prototype.getItem = function(key) {
  return window.localStorage.getItem(key);
}

StorageHandler.prototype.setItem = function(key, value) {
  return window.localStorage.setItem(key, value);
}

StorageHandler.prototype.outputKeys = function() {
  const { localStorage } = window;
  for (let i = 0; i < localStorage.length; i += 1) {
    const curKey = localStorage.key(i);
    const curVal = localStorage.getItem(curKey);
    console.log(`${curKey}: ${curVal}`);
  }
}