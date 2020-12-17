

const {inputReader} = require('competitive-programming-js');

arrange = A => {
    let n = A.length;
    for(let i=0; i<n; i++){
        A[i] = (A[A[i]]%n)*n + A[i];
    }
    for(let i=0; i<n; i++){
        A[i] = Math.floor(A[i]/n);
    }
 }

let v = inputReader.readArray();
arrange(v);
for(let i=0; i<v.length; i++) {
    console.log(v[i]);
}

