#here document(1)
#! /bin/bash
# cat << END  
# Hello World
# Java
# END

#here document(1)
#!/bin/sh
# cat <<!FUNKY!
# hello
# this is a here
# document
# !FUNKY!

#here document(3)
#! /bin/bash
ed a_text_file <<END
3
d
.,\$s/is/was
w
q
END
exit 0

#here string
grep "error" <<< "this is an error message"
