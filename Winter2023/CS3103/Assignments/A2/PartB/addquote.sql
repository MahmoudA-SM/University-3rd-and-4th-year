DELIMITER //
DROP PROCEDURE IF EXISTS addquote //

CREATE PROCEDURE addquote(IN newquote VARCHAR (255))
begin
    INSERT INTO quotes (quote) VALUES (newquote);
    end//
DELIMITER ;