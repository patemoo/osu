const template = `
        {{#each results}}
            <tr class="row" id="{{this.id}}">
                <td>{{this.name}}</td>
                <td>{{this.reps}}</td>
                <td>{{this.weight}}</td>
                <td>{{this.date}}</td>
                <td>{{this.unit}}</td>
                <td>
                    <button class="remove" onclick="window.tracker.remove({{this.id}})" title="Remove"><i class="fas fa-minus"></i></button>
                    <button class="edit" onclick="window.tracker.edit({{this.id}})"title="Edit"><i class="fas fa-pencil-alt"></i></button>
                </td>
            </tr>
            <tr class="edit-row" id="edit-{{this.id}}">
                <td colspan="6">
                    <form id="form-{{this.id}}">
                    <input class="hide" type="number" name="id" value="{{this.id}}">
                    <span class="edit-cell"><input type="text" name="name" value="{{this.name}}"></span>
                    <span class="edit-cell"><input type="number" name="reps" value="{{this.reps}}"></span>
                    <span class="edit-cell"><input type="nuber" name="weight" value="{{this.weight}}"></span>
                    <span class="edit-cell"><input type="text" name="date" value="{{this.date}}"></span>
                    <span class="edit-cell"><input type="text" name="unit" value="{{this.unit}}"></span>
                    <span class="edit-cell"><button onclick="window.tracker.update(event, {{this.id}})" title="save"><i class="fas fa-save"></i></button></span>
                </form>
                </td>
                
            </tr>
        {{/each}}
`

class Tracker {
    constructor() {

    }

    render(path) {
        let request = new XMLHttpRequest();
        request.open('GET', path, true);
        request.addEventListener('load', () => {
            if(request.status >= 200 && request.status < 400){
                let dist = document.getElementById('tbody');
                let temp = Handlebars.compile(template);
                let html = temp(JSON.parse(request.response));
                dist.innerHTML = html;
            } else {
                if (request.status === 404) {
                    alert('value not found!');
                }
                console.log("Error in network request: " + request.statusText);
            }
        });
        request.send();
    }

    clear() {
        this.render('/reset-table');
    }

    edit(id) {
        let row = document.getElementById(id);
        let editRow = document.getElementById(`edit-${id}`);
        row.classList.add('hide');
        editRow.classList.add('show');
    }

    update(event, id) {
        event.preventDefault();
        let row = document.getElementById(id);
        let editRow = document.getElementById(`edit-${id}`);
        row.classList.remove('hide');
        editRow.classList.remove('show');

        let form = document.getElementById(`form-${id}`);
        console.log(form, form.name);
        let path = `/safe-update?name=${form.name.value}&reps=${form.reps.value}&weight=${form.weight.value}&date=${form.date.value}&unit=${form.unit.value}&id=${id}`;

        this.render(path);
    }

    remove(id) {
        let path = `/delete?id=${id}`;
        this.render(path);
    }

    add(event) {
        event.preventDefault();
        let form = document.getElementById('add-form');
        let path = `/insert?name=${form.name.value}&reps=${form.reps.value}&weight=${form.weight.value}&date=${form.date.value}&unit=${form.unit.value}`;

        this.render(path);

        form.name.value = '';
        form.reps.value = '';
        form.weight.value = '';
        form.date.value = '';
        form.unit.value = '';
    }
}

window.onload = () => {
    window.tracker = new Tracker();
}