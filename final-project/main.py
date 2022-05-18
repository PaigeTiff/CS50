import smtplib
from datetime import datetime
import random
import pandas

my_gmail = "paigesloveemail@gmail.com"
password = "Angelo02"


#Check if today matches a birthday in the birthdays.csv
today = datetime.now()
today_tuple = (today.month, today.day)

#Use pandas to read the birthdays.csv
data = pandas.read_csv("/workspaces/101266499/final-project/birthdays.csv")

#Dictionary comprehension template for pandas DataFrame looks like this:
birthday_dict = {(data_row["month"], data_row["day"]): data_row for (index, data_row) in data.iterrows()}
if today_tuple in birthday_dict:
    birthday_person = birthday_dict[today_tuple]
    file_path = f"/workspaces/101266499/final-project/quotes.txt{random.randint()}.txt"
    with open('/workspaces/101266499/final-project/quotes.txt') as quote_file:
        all_quotes = quote_file.readlines()
        contents.replace("[NAME]", birthday_person["name"])
        quote = random.choice(all_quotes)

    with smtplib.SMTP("smtp.gmail.com") as connection:
        #encripts our message from hackers
        connection.starttls()
        #log into email and send message
        connection.login(user=my_gmail, password=password)
        connection.sendmail(from_addr=my_gmail, to_addrs=birthday_person["email"],
        msg=f"Subject:Happy Birthday!\n\n{quotes}")


#HINT 4: Then you could compare and see if today's month/day tuple matches one of the keys in birthday_dict like this:
# if (today_month, today_day) in birthdays_dict:

# 3. If there is a match, pick a random letter (letter_1.txt/letter_2.txt/letter_3.txt) from letter_templates and replace the [NAME] with the person's actual name from birthdays.csv
# HINT 1: Think about the relative file path to open each letter.
# HINT 2: Use the random module to get a number between 1-3 to pick a randome letter.
# HINT 3: Use the replace() method to replace [NAME] with the actual name. https://www.w3schools.com/python/ref_string_replace.asp

# 4. Send the letter generated in step 3 to that person's email address.
# HINT 1: Gmail(smtp.gmail.com), Yahoo(smtp.mail.yahoo.com), Hotmail(smtp.live.com), Outlook(smtp-mail.outlook.com)
# HINT 2: Remember to call .starttls()
# HINT 3: Remember to login to your email service with email/password. Make sure your security setting is set to allow less secure apps.
# HINT 4: The message should have the Subject: Happy Birthday then after \n\n The Message Body.





