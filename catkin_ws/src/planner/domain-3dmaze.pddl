(define (domain robots)
	(:requirements :strips :typing) ; :equality 
	(:types intersection agent)
	(:constants robot - agent)
	(:predicates

		(at ?x ?y)		; Object X is at position Y
		(adjoin ?x ?y)
		(blocked ?x ?y)

	)


	(:action move
		:parameters 	(?x ?y - intersection)
		:precondition 	(and
							(at robot ?x)
							;(not (= x? y?))
							(not (at robot ?y))
							(or (adjoin ?x ?y) (adjoin ?y ?x)) ; makes edges bidirectional
							(not (or (blocked ?x ?y) (blocked ?y ?x))) ; makes blockages bidirectional
						)
		:effect			(and
							(at robot ?y)
							(not (at robot ?x))
;								(forall (?z)
;									(when (and (inhand ?z) (not (= ?z robot)))
;										(and (at ?z ?y) (not (at ?z ?x)))))
						)
	)
)