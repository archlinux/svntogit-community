(require "asdf")

(push (uiop/os:getcwd) asdf:*central-registry*)

(asdf:load-system "rt")

(with-input-from-string (*standard-input* (format nil "\"~A/tmpfile\"" (uiop/os:getcwd)))
  (load #p"rt-test.lisp"))

(uiop:quit (if (do-tests) 0 1))
