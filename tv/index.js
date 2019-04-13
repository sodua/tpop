const puppeteer = require("puppeteer");
const fs = require("fs");

async function run() {
  const browser = await puppeteer.launch();
  const page = await browser.newPage();
	await page.goto("https://tvlistings.zap2it.com/?aid=gapzap", { waitUntil: "networkidle0" });
	const html = await page.content();
	fs.writeFileSync("index.html", html);
	await browser.close();
}

run();
