#! /usr/bin/gcl -f

; (checkInt x)
;    returns t if x is an integer,
;    otherwise displays an error message and returns nil
(defun checkInt (x)
   (cond
      ((not (integerp x)) (format t "Error: ~A is not an integer~%" x))
      (t t)))


; define a main routine that gets a value from the user,
;    checks to make sure it is an integer (using checkInt),
;    and displays the square of the value
(defun main ()
   (let ; use a local variable for the user-entered value
      ((userVal 0))  ; initialized to 0

      ; prompt the user and read their response
      (format t "Please enter an integer.~%")
      (setf userVal (read))

      ; if they entered an integer then compute and display the square,
      ; otherwise display an error message
      (cond
          ((checkInt userVal) (format t "The square of ~A is ~A~%" userVal (* userVal userVal)) )
          (t (format t "Unable to compute the square of ~A~%" userVal))
      )
   )
)

; run the main routine
(main)

