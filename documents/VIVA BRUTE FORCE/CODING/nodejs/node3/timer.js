

const timeout = setTimeout(() => {
    console.log('1.5초 후 실행');
}, 1500);

const interval = setInterval(() => {
    console.log('1초마다 실행');
}, 1000);

const timeout2 = setTimeout(() => {
    console.log('실행되지 않습니다');
}, 3000);

setTimeout(() => {
    clearTimeout(timeout2);
    clearInterval(interval);
}, 2500);



const im = setImmediate(() => console.log('즉시 실행'));
clearImmediate(im);


console.log(__filename);
console.log(__dirname);



//node는 싱글 스레드. 이 단점을 극복하기 위해 멀티 프로세싱을 사용.

console.log(process.version);
console.log(process.arch);
console.log(process.platform);
console.log(process.pid);
console.log(process.uptime());
console.log(process.cwd());
console.log(process.execPath);
console.log(process.cpuUsage());
// process.exit();












