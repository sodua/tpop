export CHROME_DEVEL_SANDBOX=~/Documents/tpop/tv/node_modules/puppeteer/.local-chromium/linux-624492/chrome-linux/chrome_sandbox

sed 's/<h5/\n&/g' index.html | sed 's/<div/\n&/g' | sed 's/<span/\n&/g' | sed 's/<\!-- react-text/\n&/g' | sed -e '/channel-card__callSign/{n;N;N;N;N;d}' |  grep -B1 -A4 "^<h5 class=\"show-card__title\">.*</h5>$" | sed 's/\(<span class=\"channel-card__callSign\">\|<\/span><\/div>\)//g' | sed 's/\(<h5 class=\"show-card__title\">\|<\/h5>\)//g'|sed 's/<div class=\"show-card__time\">//g' | sed 's/\(<\!-- react-text: [[:digit:]]\+ -->\|<\!-- \/react-text -->\)//g' | sed -n '/<span class=\"show-card__inner\">/!p'

#for PBS:
sed -n -e '/PBS/,/MNT/p' | sed -e '$d' | sed -e '$d'

# show start time of listings
grep -E -m 1 ' am|pm'

# unix date in format to compare
date +"%I:%M %P"
