(define (domain robots)
	(:requirements :strips :equality :typing)
	(:types location agent)
	(:predicates

		(at ?x - agent ?y - location)		; Object X is at position Y
		(adjoin ?x ?y - location)
		(blocked ?x ?y - location)
		(occupied ?x - location)

	)


	(:action move
		:parameters 	(?x - agent ?y ?z - location)
		:precondition 	(and
							(at ?x ?y)
							;(not (at robot ?y))
							(not (occupied ?z))
							(or (adjoin ?y ?z) (adjoin ?z ?y)) ; makes edges bidirectional
							(not (or (blocked ?y ?z) (blocked ?z ?y))) ; makes blockages bidirectional
						)
		:effect			(and
							(at ?x ?z)
							(not (at ?x ?y))
							(occupied ?z)
							(not (occupied ?y))
;								(forall (?z)
;									(when (and (inhand ?z) (not (= ?z robot)))
;										(and (at ?z ?y) (not (at ?z ?x)))))
						)
	)
)