function advicePage() {
  if (localStorage.getItem("tbRecords") ===
    null) {
    alert("No records exist.");

    $(location).attr("href", "#pageMenu");
  } else {

    //var user = JSON.parse(localStorage.getItem(
    //  "user"));

    var tbRecords = JSON.parse(localStorage.getItem(
      "tbRecords"));
    tbRecords.sort(compareDates);
    var i = tbRecords.length - 1;
    var TSH = tbRecords[i].BMI;
    var TSHLevel = tbRecords[i].BMIType;

    var c = document.getElementById(
      "AdviceCanvas");
    var ctx = c.getContext("2d");
    ctx.fillStyle = "#c0c0c0";
    ctx.fillRect(0, 0, 550, 550);
    ctx.font = "22px Arial";
    drawAdviceCanvas(ctx, TSHLevel, TSH);

  }
}

function drawAdviceCanvas(ctx, TSHLevel, TSH) {
  ctx.font = "22px Arial";
  ctx.fillStyle = "black";
  ctx.fillText("Your current BMI is " + TSH +
    ".", 25, 320);

  if (TSHLevel == "Underweight" && TSH < 10) {
    ctx.fillText(
      "Your target BMI is: 18.5",
      25, 350);
    levelDwrite(ctx, TSH);
    levelAMeter(ctx, TSH);
  } else if (TSHLevel == "Underweight" && TSH > 10) {
    ctx.fillText(
      "Your target BMI is: 18.5",
      25, 350);
    levelAwrite(ctx, TSH);
    levelAMeter(ctx, TSH);
  } else if (TSHLevel == "Normal") {
    ctx.fillText(
      "Keep up the good work!",
      25, 350);
    levelBwrite(ctx, TSH);
    levelAMeter(ctx, TSH);
  } else if (TSHLevel == "Overweight") {
    ctx.fillText(
      "Your target BMI is: 25",
      25, 350);
    levelCwrite(ctx, TSH);
    levelAMeter(ctx, TSH);
  } else if (TSHLevel == "Obese") {
    ctx.fillText(
      "Your target BMI is: 25",
      25, 350);
    levelDwrite(ctx, TSH);
    levelBMeter(ctx, TSH);
  }
}

//For deciding what to write for given values of BMI levels

function levelAwrite(ctx, TSH) {
    writeAdvice(ctx, "yellow");
  }
function levelBwrite(ctx, TSH) {
    writeAdvice(ctx, "green");
  }

function levelCwrite(ctx, TSH) {
    writeAdvice(ctx, "yellow");
}
function levelDwrite(ctx, TSH) {
    writeAdvice(ctx, "red");
  }

function writeAdvice(ctx, level) {
  var adviceLine1 = "";
  var adviceLine2 = "";

  if (level == "red") {
    adviceLine1 =
      "Please consult with your family";
    adviceLine2 = "physician urgently.";
  } else if (level == "yellow") {
    adviceLine1 =
      "Contact family physician and repeat measurements";
    adviceLine2 = "in 6-8 weeks.";
  } else if (level = "green") {
    adviceLine1 =
      "Repeat measurements in 6-8 weeks.";
  }
  ctx.fillText("Your BMI level is " + level +
    ".", 25, 380);
  ctx.fillText(adviceLine1, 25, 410);
  ctx.fillText(adviceLine2, 25, 440);
}

function levelAMeter(ctx, TSH) {
    var bcg = new RGraph.CornerGauge(
        "AdviceCanvas", 0, 45, TSH)
      .Set("chart.colors.ranges", [
        [0, 10, "red"],
        [10, 18.4, "yellow"],
        [18.5, 25, "#0f0"],
        [25.1, 30, "yellow"],
        [30, 45, "red"]
      ]);
  drawMeter(bcg);
}

function levelBMeter(ctx, TSH) {
    var bcg = new RGraph.CornerGauge(
        "AdviceCanvas", 0, 200, TSH)
      .Set("chart.colors.ranges", [
        [0, 10, "red"],
        [10, 18.4, "yellow"],
        [18.5, 25, "#0f0"],
        [25.1, 30, "yellow"],
        [30, 200, "red"]
      ]);
  drawMeter(bcg);
}

// Meter properties
function drawMeter(g) {
  g.Set("chart.value.text.units.post", " mlU/L")
    .Set("chart.value.text.boxed", false)
    .Set("chart.value.text.size", 14)
    .Set("chart.value.text.font", "Verdana")
    .Set("chart.value.text.bold", true)
    .Set("chart.value.text.decimals", 2)
    .Set("chart.shadow.offsetx", 5)
    .Set("chart.shadow.offsety", 5)
    .Set("chart.scale.decimals", 2)
    .Set("chart.title", "TSH LEVEL")
    .Set("chart.radius", 250)
    .Set("chart.centerx", 50)
    .Set("chart.centery", 250)
    .Draw();
}
