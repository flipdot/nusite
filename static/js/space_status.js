(function () {
    const icon = document.getElementById("space-status-icon");
    const tooltip = document.getElementById("space-status-tooltip");
    const tooltipCheckbox = document.getElementById("space-status-checkbox");
    const tooltipContent = tooltip.querySelector(".content");
    const mobileInfo = document.getElementById("space-status-mobile-text");

    function updateSpaceStatus(apiData) {
        if (apiData.open === true) {
            icon.classList.remove("fa-door-closed");
            icon.classList.add("fa-door-open");

            const peopleNowPresent = apiData.state.sensors.people_now_present;
            tooltipContent.innerText = `Space ist offen. ${peopleNowPresent[0].value} Geräte sind online.`;
            mobileInfo.innerText = "offen";
        } else {
            icon.classList.remove("fa-door-open");
            icon.classList.add("fa-door-closed");

            tooltipContent.innerText = "Space ist geschlossen.";
            mobileInfo.innerText = "geschlossen";
        }

        tooltipCheckbox.checked = !localStorage.getItem('flipdotStatusTooltipHidden');
    }

    // Remember whether the space status was hidden
    tooltipCheckbox.addEventListener('change', () => {
        if (tooltipCheckbox.checked) {
            localStorage.removeItem('flipdotStatusTooltipHidden');
        } else {
            localStorage.setItem('flipdotStatusTooltipHidden', 'true');
        }
    });

    const apiDataStr = sessionStorage.getItem('flipdotApiData');
    if (apiDataStr === null) {
        tooltipCheckbox.checked = false;
    } else {
        updateSpaceStatus(JSON.parse(apiDataStr));
    }

    fetch("https://api.flipdot.org/")
        .then(response => response.json())
        .then(apiData => {
            updateSpaceStatus(apiData);
            sessionStorage.setItem('flipdotApiData', JSON.stringify(apiData));
        })
        .catch(err => {
            tooltipContent.innerText = `Space-Status konnte nicht geladen werden: ${err}`;
        });
})();
