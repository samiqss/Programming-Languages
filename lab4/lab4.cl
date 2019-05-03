#! /usr/bin/gcl -f 

;Sami Al-Qusus
;csci330
;Feb 9, 2018
;Lab4

(defun buildRotate (N)
  ;set variable i to N if its an integer, else set it to 0 so that lambda immediately just returns L
  (cond
  ((not(integerp N))(defvar i 0))
   (t (defvar i N)))
  ;lambda func
  #'(lambda (L)
      (defvar temp L)
      ;loop until i=0
      (do
	((i i (- i 1)));init
	((<= i 0);stop cond. stop when ever N or in this case i, is less than 1
          temp) ;return	the modified list or same list if certain conditions didnt pass from start
	(cond ;loop body
	  ((or(not(listp temp))(eql temp nil)))
	  (t (setf temp (append (cdr temp) (list(car temp)))))))))

(defun main()
  (let
    ((L 0) (N 0))
    (format t "Please enter the values for L and N: ~%")
    (setf L(read))
    (setf N(read))
    (format t "calling buildRotate on N as ~A and lambda function on L as ~A gives:~%=> ~A ~%" N L (funcall (buildRotate N) L))
    ))

(main)
