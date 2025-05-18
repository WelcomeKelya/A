% Facts: Symptoms of illnesses
illness(flu) :- 
    symptom(fever), 
    symptom(cough), 
    symptom(sore_throat).

illness(cold) :- 
    symptom(runny_nose), 
    symptom(sneezing), 
    symptom(sore_throat).

illness(covid19) :- 
    symptom(fever), 
    symptom(cough), 
    symptom(loss_of_taste), 
    symptom(shortness_of_breath).

% Asking user about symptoms
ask(S) :- 
    write('Do you have '), write(S), write('? (yes/no): '), 
    read(Reply), 
    Reply = yes.

% Collect symptoms from user
symptom(S) :- 
    ask(S).
