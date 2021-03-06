<div>
    <table class="table table-striped">
        <thead>
            <tr>
                <th>Symbol</th>
                <th>Name</th>
                <th>Shares</th>
                <th>Price</th>
                <th>Total</th>
            </tr>
        </thead>
        <tbody class="text-left">
            <?php foreach ($positions as $position): ?>
                <tr>
                    <td><?= $position["symbol"] ?></td>
                    <td><?= $position["name"] ?></td>
                    <td><?= $position["shares"] ?></td>
                    <td><?= number_format($position["price"], 2) ?></td>
                    <td><?= number_format($position["total"], 2) ?></td>
                </tr>
            <?php endforeach ?>
            <tr>
                <td colspan="4">CASH</td>
                <td>$<?=number_format($users[0]["cash"], 2)?></td>
            </tr>
        </tbody>
    </table>
</div>
<div>
    <a href="logout.php">Log Out</a>
</div>
