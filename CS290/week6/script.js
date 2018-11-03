window.onload = () => {
    let form = document.querySelector('form');
    let submitButton = document.querySelector('button#submit');

    submitButton.onclick = (event) => {
        event.preventDefault();
        
        let value = form.search.value;

        if (value) {
            getWeather(value);
        } else {
            alert ('Please enter a city or zipcode!');
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
