// 2-7. 콜백과 프로미스(Promise) 비교


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

*/



// 2-8. 프로미스(Promise) 이해하기

const plus = new Promise((resolve, reject) => {
   const a = 1;
   const b = 2;

   if(a + b > 2){
       resolve(a + b);
   }else{
       reject(a + b);
   }
});


plus
.then((success) => {
    console.log(success);
})
.catch((fail) => {
    console.error(fail);
}); // 3



const condition = true;
const promise = new Promise((resolve, reject) => {
    if(condition){
        resolve('성공');
    }else{
        reject('실패');
    }
});

promise
    .then((message) => {
        console.log(message);
    })
    .catch((error) => {
        console.error(error);
    });



promise
    .then((message) => {
        return new Promise((resolve, reject) => {
           resolve(message);
        });
    })
    .then((message2) => {
        console.log(message2);
        return new Promise((resolve, reject) => {
            // resolve(message2);
            reject(message2);
        });
    })
    .then((message3) => {

        console.log(message3);

    })
    .catch((error) => {
        console.error(error);
    });


