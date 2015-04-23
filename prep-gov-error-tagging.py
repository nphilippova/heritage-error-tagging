#-*- coding: utf-8 -*-

import os
import codecs
import re

lemmedtext = os.system(u'mystem -cig --eng-gr heritage_text.txt text_morph.txt')
text = codecs.open(u'text_morph.txt', 'r', 'utf-8')


newtext = text.read()
tokens = re.split(u'\s+', newtext)

new_tokens = []
used_tokens = []

v_rules = ['S,m,inan=(acc,sg|nom,sg)', 'S,f,inan=nom,sg', 'S,m,inan=(acc,pl|gen,sg|nom,pl)', 'S,f,inan=(acc,pl|gen,sg|nom,pl)', 'S,m,inan=gen,pl', 'S,f,inan=gen,pl', 'S,m,inan=ins,sg', 'S,f,inan=ins,sg', 'S,m,inan=ins,pl', 'S,f,inan=ins,pl', 'S,m,inan=(dat,sg|part,sg|loc,sg)', 'S,m,inan=dat,pl', 'S,f,inan=dat,pl' ]

na_rules = ['S,f,inan=nom,sg', 'S,f,inan=gen,pl', 'S,m,inan=gen,sg', 'S,m,inan=gen,pl', 'S,m,inan=dat,sg', 'S,f,inan=dat,pl', 'S,m,inan=dat,pl', 'S,m,inan=ins,sg', 'S,f,inan=ins,sg', 'S,f,inan=ins,pl', 'S,m,inan=ins,pl']

o_rules = ['S,m,inan=(acc,sg|nom,sg)', 'S,f,inan=nom,sg', 'S,f,inan=nom,pl', 'S,m,inan=nom,pl', 'S,m,inan=(acc,pl|gen,sg|nom,pl)', 'S,f,inan=(acc,pl|gen,sg|nom,pl)', 'S,m,inan=gen,pl', 'S,f,inan=gen,pl', 'S,m,inan=ins,sg', 'S,f,inan=ins,sg', 'S,m,inan=ins,pl', 'S,f,inan=ins,pl', 'S,m,inan=(dat,sg|part,sg|loc,sg)', 'S,m,inan=dat,pl', 'S,f,inan=dat,pl']

pod_za_rules = ['S,f,inan=(abl,sg|dat,sg)', 'S,f,inan=nom,sg', 'S,m,inan=gen,pl', 'S,f,inan=gen,pl', 'S,m,inan=(dat,sg|part,sg|loc,sg)', 'S,m,inan=dat,pl', 'S,f,inan=dat,pl']
            
def check_token(rules, token):
    for rule in rules:
        if rule in token:
            return True
        
for listnumb in range(len(tokens)):
    token1 = tokens[listnumb]
    if token1 not in used_tokens:
        if u'{в=PR=' in token1:
            if listnumb < len(tokens):
                token2 = tokens[listnumb + 1]
                token3 = tokens[listnumb + 2]
                if u'=A=' in token2:
                    if check_token(v_rules, token3) is True:
                        final_token = u'<error="gov">' + token1 + u' ' + token2 + u' ' + token3 + u'</error>'
                        new_tokens.append(final_token)
                        used_tokens.append(token2)
                        used_tokens.append(token3)
                    else:
                        final_token = token1 + u' ' + token2 + u' ' + token3
                        new_tokens.append(final_token)
                        used_tokens.append(token2)
                        used_tokens.append(token3)
                else:
                    if check_token(v_rules, token2) is True:
                        final_token = u'<error="gov">' + token1 + u' ' + token2 + u'</error>'
                        new_tokens.append(final_token)
                        used_tokens.append(token2)
                    else:
                        new_tokens.append(token1)
                        new_tokens.append(token2)
                        used_tokens.append(token2)
        elif u'на{на=PR=|на=PART=}' in token1:
            if listnumb < len(tokens):
                token2 = tokens[listnumb + 1]
                token3 = tokens[listnumb + 2]
                if u'=A=' in token2:
                    if check_token(na_rules, token3) is True:
                        final_token = u'<error="gov">' + token1 + u' ' + token2 + u' ' + token3 + u'</error>'
                        new_tokens.append(final_token)
                        used_tokens.append(token2)
                        used_tokens.append(token3)
                    else:
                        print check_token(na_rules, token3)
                        final_token = token1 + u' ' + token2 + u' ' + token3
                        new_tokens.append(final_token)
                        used_tokens.append(token2)
                        used_tokens.append(token3)
                else:
                    if check_token(na_rules, token2) is True:
                    final_token = u'<error="gov">' + token1 + u' ' + token2 + u'</error>'
                    new_tokens.append(final_token)
                    used_tokens.append(token2)
                else:
                    new_tokens.append(token1)
                    new_tokens.append(token2)
                    used_tokens.append(token2)
                
            else:
                new_tokens.append(token1)
        else:
            new_tokens.append(token1)
            
pre_final_text = ' '.join(new_tokens)
final_text = re.sub('\{\S+\}', '', pre_final_text)


outfile = codecs.open(u'tagged.txt', 'w', 'utf-8')
outfile.write(final_text)
outfile.close()
