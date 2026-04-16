-- UserEvent VeryLazy，触发
vim.api.nvim_create_autocmd("User", {
    pattern = "VeryLazy",
    callback = function()
        vim.lsp.config("clangd", require("esp32").lsp_config())
        vim.lsp.enable("clangd")
    end,
})

return {
    {
        "Aietes/esp32.nvim",
        lazy = false,
        opts = {
            build_dir = "build",
        },
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
