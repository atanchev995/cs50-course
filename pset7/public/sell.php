<?php

    // configuration
    require("../includes/config.php");
    
    $rows = query("SELECT symbol FROM portfolio WHERE id = ?", $_SESSION["id"]);
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "symbol" => $row["symbol"]
            ];
        }
    }
    
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // lookup stock
        $stock = lookup($_POST["symbol"]);
        
         // lookup user's shares of stock being sold
        $shares = query("SELECT shares FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        // calculate total sale value (stock's price * shares)
        $value = $stock["price"] * $shares[0]["shares"];
        
        // add the sale value to cash
        query("UPDATE users SET cash = cash + ? WHERE id = ?", $value, $_SESSION["id"]);
        
        // delete the stock from their portfolio 
        query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
    
        // redirect to portfolio 
        redirect("/");
    }
    else
    {
        render("sell_form.php", ["positions" => $positions, "title" => "Sell"]);
    }
    
?>
