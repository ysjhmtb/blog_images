// const parseCookies = (cookie = '') =>
//     cookie
//         .split(';')
//         .map(v => v.split('='))
//         .map(([k, ...vs]) => [k, vs.join('=')])
//         .reduce((acc, [k, v]) => {
//             acc[k.trim()] = decodeURIComponent(v);
//             return acc;
//         }, {});

const parseCookies = (cookie = '') =>
    cookie
        .split(';')
        .map(v => {
            console.log('v : ' + v);
            console.log('v.split(\'=\') : ' + v.split('='));
            return v.split('=');
        })
        .map(([k, ...vs]) => {
            console.log('k : ' + k);
            console.log('vs : ' + vs);
            console.log('vs.join(\'=\') : ' + vs.join('='));
            console.log('[k, vs.join(\'=\')] : ' + [k, vs.join('=')]);

            return [k, vs.join('=')];
        })
        .reduce((acc, [k, v]) => {

            console.log('acc : ' + acc);
            console.log('[k, v] : ' + [k, v]);
            console.log('k.trim() : ' + k.trim());

            acc[k.trim()] = decodeURIComponent(v);
            console.log('acc[k.trim()] : ' + acc[k.trim()])
            return acc;
        }, {});

/*
v : name=zerocho
v.split('=') : name,zerocho

v : year=1994
v.split('=') : year,1994

k : name
vs : zerocho
vs.join('=') : zerocho
[k, vs.join('=')] : name,zerocho

k : year
vs : 1994
vs.join('=') : 1994
[k, vs.join('=')] : year,1994

acc : [object Object]
[k, v] : name,zerocho
k.trim() : name
acc[k.trim()] : zerocho

acc : [object Object]
[k, v] : year,1994
k.trim() : year
acc[k.trim()] : 1994

{ name: 'zerocho', year: '1994' }
 */

console.log(parseCookies('name=zerocho;year=1994'));
//{ name: 'zerocho', year: '1994' }





