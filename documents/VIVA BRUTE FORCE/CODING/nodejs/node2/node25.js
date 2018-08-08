// 2-9. 프로미스(Promise) API

const successPromise = Promise.resolve('성공')
    .then();
const failurePromise = Promise.reject('실패')
    .catch();



// 2-10. async/await

/*

Users.findOne('zero')
    .then((user) => {
    console.log(user);
    return Users.update('zero','nero');
    })
    .then((updateUser) => {
        console.log(updateUser);
        return Users.remove('nero');
    })
    .then((removeUser) => {
        console.log(removeUser);
    })
    .catch((err) => {
        console.error(error);
    });

    console.log('다 찾았니?');

'다 찾았니?'가 먼저 출력된다.


이 문제의 해결을 위해서,

async func() => {

    try{
        const user = await Users.findOne('zero');
        const updatedUser = await Users.update('zero', 'nero');
        const removedUser = await User.remove('nero');
        console.log('다 찾았니');
    } catch (e) {
        console.error(e);
    }

}

func();
 */

