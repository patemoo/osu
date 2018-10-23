window.onload = () => {

    // page styles
    let styles = document.createElement('style');
    styles.innerText = `
        body {
            text-align: center;
            font-family: arial, sans-serif;
        }
        table {
            width: 100%;
            max-width: 600px;
            margin: 40px auto;
        }
        td {
            padding: 10% 0;
            border: 1px solid;
            
        }
        td.selected {
            border: 3px solid;
        }
        td.marked {
            background-color: yellow;
        }
        button {
            margin: 4px;
            padding: 4px 8px;
            background-color: transparent;
            border: 2px solid;
        }
        .mark-button {
            margin-left: 16px;
        }
    `;
    document.body.appendChild(styles);

    let table = document.createElement('table');

    let headRow = document.createElement('tr');

    // create table head cells
    for (let i=0; i < 4; i++) {
        let th = document.createElement('th');
        th.innerHTML = `Header ${i+1}`;
        headRow.appendChild(th);
    }

    table.appendChild(headRow);
    
    // create table body cells
    for (let j=0; j < 3; j++) {
        let tr = document.createElement('tr');

        for (let i=0; i < 4; i++) {
            let td = document.createElement('td');
            td.id = `cell-${j+1}-${i+1}`;
            td.innerHTML = `${j+1}, ${i+1}`;
            tr.appendChild(td);
        }

        table.appendChild(tr);
    }

    document.body.appendChild(table);
    
    // this class manages which cell is slected as well as marking of cells.
    class SelectedCell {
        constructor () {
            this.row = 1;
            this.column = 1;
            this.currentCell;
        }
        update() {
            let id = 'cell-' + this.row + '-' + this.column;
            let newCell = document.getElementById(id);
            newCell.classList.add('selected');
            if (this.currentCell) {
                this.currentCell.classList.remove('selected');
            }
            this.currentCell = newCell;
        }
        move(direction) {
            let change = false;
            switch (direction) {
                case 'up':
                    if (this.row > 1) {
                        this.row--;
                        change = true;
                    }
                break;
                case 'right':
                    if (this.column < 4) {
                        this.column++;
                        change = true;
                    }
                break;
                case 'down':
                    if (this.row < 3) {
                        this.row++;
                        change = true;
                    }
                break;
                case 'left':
                    if (this.column > 1) {
                        this.column--;
                        change = true;
                    }
                break;
            }
            if (change) {
                this.update();
            }
        }
        mark() {
            this.currentCell.classList.add('marked');
        }
    }

    let cell = new SelectedCell;

    cell.update();

    // buttons
    let upButton = document.createElement('button')
    upButton.innerText = 'UP';
    upButton.onclick = () => {
        cell.move('up');
    }
    document.body.appendChild(upButton);

    let downButton = document.createElement('button')
    downButton.innerText = 'DOWN';
    downButton.onclick = () => {
        cell.move('down');
    }
    document.body.appendChild(downButton);

    let leftButton = document.createElement('button')
    leftButton.innerText = 'LEFT';
    leftButton.onclick = () => {
        cell.move('left');
    }
    document.body.appendChild(leftButton);

    let rightButton = document.createElement('button')
    rightButton.innerText = 'RIGHT';
    rightButton.onclick = () => {
        cell.move('right');
    }
    document.body.appendChild(rightButton);

    let markButton = document.createElement('button');
    markButton.classList.add('mark-button');
    markButton.innerText = 'Mark Cell';
    markButton.onclick = () => {
        cell.mark();
    };
    document.body.appendChild(markButton);

    // support for arrow keys movement end enter key marking
    document.addEventListener('keyup', (event) => {
        switch(event.key) {
            case 'ArrowUp':
                cell.move('up');
                break;
            case 'ArrowRight':
                cell.move('right');
                break;
            case 'ArrowDown':
                cell.move('down');
                break;
            case 'ArrowLeft':
                cell.move('left');
                break;
            case 'Enter':
                cell.mark();
                break;
        }
    });
}

