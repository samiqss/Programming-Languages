#! /usr/bin/gcl -f

;Sami Al-Qusus
;csci330
;Jan 19, 2018
;Lab1

(defun classify (x)
  (cond 
    ((numberp x) (format t "~A is a number~%" x))
    ((stringp x) (format t "~A is a string~%" x))
    ((listp x) (format t "~A is a list~%" x))
    (t (format t "~A is not a number, string, or list~%" x))))

(defun summation (x y z)
  (cond
    ((and (numberp x)(numberp y)(numberp z))(+ x y z))
    ((and (not(numberp x))(numberp y)(numberp z))(+ y z))
    ((and (numberp x)(numberp y)(not(numberp z)))(+ x y))
    ((and (numberp x)(not(numberp y))(numberp z))(+ x z))
    ((and (numberp x)(not(numberp y))(not(numberp z)))(x))
    ((and (not(numberp x))(numberp y)(not(numberp z)))(y))
    ((and (not(numberp x))(not(numberp y))(numberp z))(z))
    (t 0)
    ))



(defun main ()
  (let ;uses a local variable for user-entered value
    ((var1 0)(var2 0)(var3 0)) ; initialized to 0
    (format t "Please enter three numbers~%")
    (setf var1(read))
    (setf var2(read))
    (setf var3(read))
    ;call function classify 
    (classify var1)
    (classify var2)
    (classify var3)
    ;call function summation here
    (format t "the sum of ~A, ~A  and ~A is: ~A ~%" var1 var2 var3 (summation var1 var2 var3))
    ))

; run the main function
(main)

