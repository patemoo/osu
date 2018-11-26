class Tracker {
    constructor() {

    }

    clear() {
        document.location = '/reset-table';
    }

    edit() {
        
    }

    update() {
        document.location = '/';
    }

    remove(id) {
        document.location = '/';
    }
}



window.onload = () => {
    window.tracker = new Tracker();
}