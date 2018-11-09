/* Enables pressing the keyboard Enter key to 
 * submit a password attempt
*/

$(function() {
  $("#passcode").keypress(function(e) {
    if (e.keyCode == 13) {
	  $("#btnEnter").trigger('click');
	}
  })
});

/* Adds given text value to the password text 
 * field
 */

const btns = Array.from(document.querySelectorAll(".btn"));
for (var i = 0; i < btns.length; i++) (function(i) {
  btns[i].onclick = function() {
    var currVal = $("#passcode").val();
    var numPad = btns[i].getAttribute("value");
    if (numPad == "bksp") {
      $("#passcode").val(currVal.substring(0, currVal.length - 1));
    } else {
      $("#passcode").val(currVal.concat(numPad))
    } 
  }
})(i);

/* 
 * Retrieves password from local storage if it
 * exists, otherwise returns the default password
 */
function getPassword() {
  if (typeof (Storage) == "undefined") {
    alert(
      "Your browser does not support HTML5 localStorage. Try upgrading."
    );
  } else if (localStorage.getItem("user") !=
    null) {
    return JSON.parse(localStorage.getItem(
      "user")).NewPassword;
  } else {
    /*Default password*/
    return "2345";
  }
}

/* On the main page, after password entry, directs
 * user to main page, legal disclaimer if they
 * have not yet agreed to it, or user entry page
 * if they have not yet completed their user info.
 */
$("#btnEnter").click(function () {
  var password = getPassword();

  if (document.getElementById("passcode").value ==
    password) {
    if (localStorage.getItem("agreedToLegal") ==
      null) {
      $("#btnEnter").attr("href",
        "#legalNotice").button();
    } else if (localStorage.getItem(
        "agreedToLegal") == "true") {
      if (localStorage.getItem("user") ==
        null) {
        /* User has not been created, direct user 
         * to User Creation page
         */
        $("#btnEnter").attr("href",
          "#pageUserInfo").button();
      } else {
        $("#btnEnter").attr("href",
          "#pageMenu").button();
      }
    }
  } else {
    alert(
      "Incorrect password, please try again."
    );
  }
});

/* Records that the user has agreed to the legal
 * disclaimer on this device/browser
 */
$("#noticeYes").click(function () {
  localStorage.setItem("agreedToLegal",
    "true");
});
