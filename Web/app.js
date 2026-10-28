const basicButton = document.getElementById("basic-button");

const basicCalculator = document.getElementById("basic-calculator");

const backButton = document.getElementById("back-button");

basicButton.addEventListener("click", function () {
    document.querySelector(".main-menu").hidden = true;
    basicCalculator.hidden = false;
});

backButton.addEventListener("click", function () {
    basicCalculator.hidden = true;
    document.querySelector(".main-menu").hidden = false;
});