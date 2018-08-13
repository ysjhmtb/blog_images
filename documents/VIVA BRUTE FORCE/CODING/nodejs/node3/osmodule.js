const os = require('os');

console.log(os.arch());
console.log(os.platform());
console.log(os.type());

//process.uptime()은 노드가 실행된 후 흐른 시간.
//여기서는 운영체제가 시작되고 흐른 시간.
console.log(os.uptime());

console.log(os.hostname());
console.log(os.release());
console.log(os.homedir());

console.log(os.tmpdir());

//추가로 사용가능한 메모리
console.log(os.freemem());
//총 메모리
console.log(os.totalmem());

console.log(os.cpus());