from selenium import webdriver
driver = webdriver.PhantomJS()
driver.get('http://tel.local/js/index.html')
p_element = driver.find_element_by_id(id_='intro-text')
print(p_element.text)
