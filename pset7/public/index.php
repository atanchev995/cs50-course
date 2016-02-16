<?php

    // configuration
    require("../includes/config.php");
    
    $rows = query("SELECT symbol, shares FROM portfolio WHERE id = ?", $_SESSION["id"]);
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"],
                "total" => $row["shares"] * $stock["price"]
            ];
        }
    }

    // query cash for template
    $users = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
    
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "users" => $users, "title" => "Portfolio"]);

?>
