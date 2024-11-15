((org-mode . ((eval . (add-hook 'after-save-hook
                                (lambda nil
                                  (when
                                      (string-equal
                                       (file-name-nondirectory buffer-file-name)
                                       "README.org")
                                    (org-pandoc-export-to-gfm)))
                                nil t))))
 ((nil . ((org-roam-directory . "~/workspace/ft_printf/notes")
          (org-roam-db-location . "~/workspace/ft_printf/notes/ft_printf.db"))))
 )
