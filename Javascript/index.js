//Write a web page with a 400x400 pixel canvas and a single button.
// Using jquery to listen for the button click event, draw a circle 1/2 the size of the canvas in the upper right-hand corner of the canvas
// and an ellipse in the lower left-hand corner of the canvas. Fill both the circle and the ellipse.

// Button event
$(document).ready(function() {
    $("#Button").on('click', function(event) {
        var canvas = document.getElementById("Canvas");
        var ctx = canvas.getContext("2d");
        // Draw a circle 1/2 the size of the canvas in the upper right-hand corner of the canvas and fill it.
        ctx.beginPath();
        ctx.arc(299, 101, 100, 0, 2 * Math.PI);
        ctx.fillStyle = 'black';
        ctx.fill();
        ctx.stroke();

        // Draw an ellipse in the lower left-hand corner of the canvas and fill it.
        ctx.beginPath();
        ctx.ellipse(151, 299, 150, 100, 0, 0, 2 * Math.PI);
        ctx.fillStyle = 'black';
        ctx.fill();
        ctx.stroke();

        event.preventDefault();
    });
});