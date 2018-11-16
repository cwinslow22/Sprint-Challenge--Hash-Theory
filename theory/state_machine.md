# Possible states 
normal output
special mode output

# possible transitions
no escape sequence -> normal output
escape sequence triggered by Esc[ -> special mode output


# Graph Legend

## transitions
'Non-Esc' any input not preceded by 'Esc['
'Esc[' input preceded by 'Esc['

## states
'Normal mode'  the default mode
'Special mode' triggered by an 'Esc[' sequence