

funOne();

function funOne() {
    console.log('this should run');
}

funTwo();

var funTwo = () => {
    console.log('this should not run');
}