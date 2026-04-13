-- UserEvent VeryLazy，触发
vim.api.nvim_create_autocmd("User", {
    pattern = "VeryLazy",
    callback = function()
        vim.lsp.config("clangd", require("esp32").lsp_config())
    end,
})

return {
    {
        "Aietes/esp32.nvim",
        opts = {},
        keys = {
            {
                "<leader>,e",
                function()
                    require("esp32").pick("monitor")
                end,
                desc = "ESP32: Pick & Monitor",
            },
        },
    },
}
