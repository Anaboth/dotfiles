(setq inhibit-startup-screen t)
(set-default-font "Source Code Pro Semibold-10")
(menu-bar-mode 0)
(tool-bar-mode 0)
(ido-mode 1)
(require 'package)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/"))
(package-initialize)
(custom-set-variables
 '(custom-safe-themes
   (quote
    ("6ee6f99dc6219b65f67e04149c79ea316ca4bcd769a9e904030d38908fd7ccf9" default)))
 '(package-selected-packages
   (quote
    (darcula-theme darkokai-theme evil elpy smex melancholy-theme))))
(custom-set-faces
 )
(require 'evil)
(evil-mode 1)
(load-theme 'darkokai t)
(scroll-bar-mode -1)
(global-set-key (kbd "M-x") 'smex)
(global-set-key (kbd "M-X") 'smex-major-mode-commands)
(define-key text-mode-map (kbd "<tab>") 'tab-to-tab-stop)
(setq tab-stop-list (number-sequence 4 120 4))
