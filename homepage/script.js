document.addEventListener('DOMContentLoaded', function() {
    setInterval(function() {
        var blinkingText = document.getElementById('blinkingText');
        blinkingText.classList.toggle('blinking');
    }, 400); // Adjust the interval duration (milliseconds)
});
