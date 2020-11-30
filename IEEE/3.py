import xml.sax
import re


# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield (number)


input_parser = parser()
indices = {}
weights = {"title": 5, "abstract": 3, "body": 1}
dic = {}
totalCount = 0


def get_word():
    global input_parser
    return next(input_parser)


def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)


class CountHandler(xml.sax.ContentHandler):
    def __init__(self):
        self.id = ""
        self.content = ""
        self.count = 0

    def startElement(self, tag, attributes):
        pass
        if tag in weights.keys():
            self.id = tag

    def endElement(self, tag):
        if tag in weights.keys():
            self.id = ""

    def characters(self, content):
        pass
        # if self.id in weights.keys():
        #     words = content.split()
        #     for word in words:
        #         t = word.lower()
        #         t = t.replace('.', '')
        #         t = t.replace(',', '')
        #         t = t.replace('?', '')
        #         t = t.replace('!', '')
        #         print(t)
        # t = t.replace("'", '')
        # if len(t) >= 4 and t not in indicesStop:
        #     self.count += 1
        # if t in indices and self.id in weights.keys():
        #     dic[t] += weights[self.id]


rawStop = get_word()
rawIndex = get_word()
rawXml = ""

try:
    while True:
        s = input()
        rawXml = rawXml + s + "\n"
except EOFError:
    pass

indicesStop = rawStop.split(";")
indices = rawIndex.split(";")

for index in indices:
    dic[index] = 0
handler = CountHandler()
xml_dom = xml.sax.parseString(rawXml, handler)
# dicSorted = sorted(dic.items(), key = lambda item:item[1], reverse=True)
# count = 0
# for item in dicSorted:
#     if count == 3:
#         count += 1
#         break
#     print(item[0], end='')
#     print(":", item[1] / handler.count * 100)
#     count += 1

# while dicSorted[count][1] == dicSorted[2][1]:
#     print(dicSorted[count][0], end='')
#     print(":", dicSorted[count][1] / handler.count * 100)
#     count += 1


