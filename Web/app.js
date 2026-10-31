/* Basic Calculator */
const basicButton = document.getElementById("basic-button");
const basicCalculator = document.getElementById("basic-calculator");
const backButton = document.getElementById("back-button");

/* Number System Converter */
const converterButton = document.getElementById("converter-button");
const converter = document.getElementById("converter");
const converterBackButton = document.getElementById("converter-back-button");

const conversionType = document.getElementById("conversion-type");
const conversionInput = document.getElementById("conversion-input");

/* Bitwise Calculator */
const bitwiseButton = document.getElementById("bitwise-button");
const bitwiseCalculator = document.getElementById("bitwise-calculator");
const bitwiseBackButton = document.getElementById("bitwise-back-button");

const bitwiseOperation = document.getElementById("bitwise-operation");
const bitwiseSecondInput = document.getElementById("bitwise-second-input");

const bitwiseFirstInput = document.getElementById("bitwise-first-input");

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

conversionType.addEventListener("change", function () {
    if (
        conversionType.value === "decimal-binary" ||
        conversionType.value === "decimal-hex" ||
        conversionType.value === "decimal-octal"
    ) {
        conversionInput.placeholder = "Enter decimal number";

    } else if (
        conversionType.value === "binary-decimal" ||
        conversionType.value === "binary-octal"
    ) {
        conversionInput.placeholder = "Enter binary number";

    } else if (conversionType.value === "hex-decimal") {
        conversionInput.placeholder = "Enter hexadecimal number";

    } else if (conversionType.value === "octal-binary") {
        conversionInput.placeholder = "Enter octal number";
    }
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

bitwiseOperation.addEventListener("change", function () {
    if (bitwiseOperation.value === "not") {
        bitwiseFirstInput.placeholder = "Enter binary number";
        bitwiseSecondInput.hidden = true;

    } else if (
        bitwiseOperation.value === "left-shift" ||
        bitwiseOperation.value === "logical-right-shift" ||
        bitwiseOperation.value === "arithmetic-right-shift"
    ) {
        bitwiseFirstInput.placeholder = "Enter binary number";
        bitwiseSecondInput.hidden = false;
        bitwiseSecondInput.placeholder = "Enter shift amount";

    } else {
        bitwiseFirstInput.placeholder = "Enter first binary number";
        bitwiseSecondInput.hidden = false;
        bitwiseSecondInput.placeholder = "Enter second binary number";
    }
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
