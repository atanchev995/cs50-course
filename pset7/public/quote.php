<?php

    // configuration
    require("../includes/config.php"); 

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // Validate the name
        if (empty($_POST["symbol"]))
        {
            apologize("Please enter the stock symbol.");
        }
        
        // Lookup stock from Yahoo
        $stock = lookup($_POST["symbol"]);
        
        // Validate the symbol
        if ($stock === false)
        {
            apologize("Invalid symbol.");
        }
        else
        {
            // Show the result
            $price = $stock["price"];
            render("quote.php", ["title" => "Quote", "symbol" => $stock["symbol"], "name" => $stock["name"], "price" => $stock["price"]]);
        }
    }
    else
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }

?>
