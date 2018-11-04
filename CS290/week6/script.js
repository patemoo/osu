window.onload = () => {
    let weatherform = document.querySelector('form#weather-form');
    let weatherSubmitButton = document.querySelector('button#submit-weather');

    let textForm = document.querySelector('form#text-form');
    let textSubmitButton = document.querySelector('button#submit-text');

    weatherSubmitButton.onclick = (event) => {
        event.preventDefault();
        
        let value = weatherform.search.value;

        if (value) {
            getWeather(value);
        } else {
            alert ('Please enter a city or zipcode!');
        }
    }

    textSubmitButton.onclick = (event) => {
        event.preventDefault();

        let value = textForm.sendText.value;

        if (value) {
            sendText(value);
        } else {
            alert ('Please enter a text string');
        }
    }
}

let getWeather = (value) => {
    let weatherStorage = window.localStorage;
    let weatherString = weatherStorage.getItem(value) || '';
    let path = '';

    if (weatherString) {
        displayWeather(JSON.parse(weatherString));
    } else {
        if (isNaN(Number(value))) {
            path = `http://api.openweathermap.org/data/2.5/weather?q=${value},us&units=imperial&APPID=3b5639aea1a96c6c551d801ffbc2a7f5`;
        } else if (RegExp(/^[0-9]{5}(?:-[0-9]{4})?$/).test(value)) {
            path = `http://api.openweathermap.org/data/2.5/weather?zip=${value},us&units=imperial&APPID=3b5639aea1a96c6c551d801ffbc2a7f5`;   
        } else {
            return alert ('invalid zipcode!');
        }

        let request = new XMLHttpRequest();
        request.open('GET', path, true);
        request.addEventListener('load', () => {
            if(request.status >= 200 && request.status < 400){
                weatherString = request.responseText;
                window.localStorage.setItem(value, weatherString);

                displayWeather(JSON.parse(weatherString));
            } else {
                if (request.status === 404) {
                    alert('value not found!');
                }
                console.log("Error in network request: " + request.statusText);
            }
        });
        request.send();
    }
}

let displayWeather = (weatherObject) => {
    clear();
    let city = document.getElementById('city');
    let temp = document.getElementById('temp');
    let icon = document.getElementById('icon');
    let description = document.getElementById('description');
    let display = {
        city: weatherObject.name,
        temp: weatherObject.main.temp,
        weather: weatherObject.weather[0].main,
        description: weatherObject.weather[0].description,
        iconSrc: `http://openweathermap.org/img/w/${weatherObject.weather[0].icon}.png`,
        
    }

    city.innerText = display.city;
    icon.setAttribute('src', display.iconSrc)
    temp.innerText = Math.floor(display.temp);
    temp.hidden = false;
    description.innerText = display.description;
}

let sendText = (value) => {
    let payload = value;
    let result = document.getElementById('text-result');

    let request = new XMLHttpRequest();
    request.open('POST', 'http://httpbin.org/post', true);
    request.setRequestHeader('Content-Type', 'application/json');
    request.addEventListener('load', () => {
        if(request.status >= 200 && request.status < 400){
            let response = JSON.parse(request.responseText);
            clear();
            result.innerText = response.data;
        } else {
            console.log("Error in network request: " + request.statusText);
        }
    });
    request.send(JSON.stringify(payload));
}

let clear = () => {
    let city = document.getElementById('city');
    let temp = document.getElementById('temp');
    let icon = document.getElementById('icon');
    let description = document.getElementById('description');

    let result = document.getElementById('text-result');

    city.innerText = '';
    icon.setAttribute('src', '#')
    temp.innerText = '';
    temp.hidden = true;
    description.innerText = '';

    result.innerText = '';
}