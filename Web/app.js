/* Basic Calculator */
const basicButton = document.getElementById("basic-button");
const basicCalculator = document.getElementById("basic-calculator");
const backButton = document.getElementById("back-button");

/* Number System Converter */
const converterButton = document.getElementById("converter-button");
const converter = document.getElementById("converter");
const converterBackButton = document.getElementById("converter-back-button");

/* Bitwise Calculator */
const bitwiseButton = document.getElementById("bitwise-button");
const bitwiseCalculator = document.getElementById("bitwise-calculator");
const bitwiseBackButton = document.getElementById("bitwise-back-button");

/* Two's Complement */
const twosButton = document.getElementById("twos-button");
const twosComplement = document.getElementById("twos-complement");
const twosBackButton = document.getElementById("twos-back-button");

/* Basic Calculator */
basicButton.addEventListener("click", function () {
    document.querySelector(".main-menu").hidden = true;
    basicCalculator.hidden = false;
});

backButton.addEventListener("click", function () {
    basicCalculator.hidden = true;
    document.querySelector(".main-menu").hidden = false;
});

/* Number System Converter */
converterButton.addEventListener("click", function () {
    document.querySelector(".main-menu").hidden = true;
    converter.hidden = false;
});

converterBackButton.addEventListener("click", function () {
    converter.hidden = true;
    document.querySelector(".main-menu").hidden = false;
});

/* Bitwise Calculator */
bitwiseButton.addEventListener("click", function () {
    document.querySelector(".main-menu").hidden = true;
    bitwiseCalculator.hidden = false;
});

bitwiseBackButton.addEventListener("click", function () {
    bitwiseCalculator.hidden = true;
    document.querySelector(".main-menu").hidden = false;
});

/* Two's Complement */
twosButton.addEventListener("click", function () {
    document.querySelector(".main-menu").hidden = true;
    twosComplement.hidden = false;
});

twosBackButton.addEventListener("click", function () {
    twosComplement.hidden = true;
    document.querySelector(".main-menu").hidden = false;
});