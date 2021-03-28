# Maintainer: Ronald van Haren <ronald@archlinux.org>

pkgname=ttf-inconsolata
pkgver=3.000
pkgrel=3
epoch=1
pkgdesc="Monospace font for pretty code listings and for the terminal"
arch=('any')
url="https://www.google.com/fonts/specimen/Inconsolata"
license=('custom:OFL')
depends=()
source=("https://github.com/googlefonts/Inconsolata/releases/download/v$pkgver/fonts_ttf.zip"
        "https://github.com/googlefonts/Inconsolata/releases/download/v$pkgver/OFL.txt"
        "https://github.com/googlefonts/Inconsolata/releases/download/v$pkgver/FONTLOG.txt"
        '75-ttf-inconsolata.conf')
sha256sums=('626e8ee07501dbb544b50aa59ac2e4b9ec86b810670158a59c7a3cbaf475548a'
            '5d362a6f8690517fd9a5573128a081d8bbbb2f92714cf00556e08fbbe9600426'
            '73f3109ad0986c8ec7d117dab344e940e4e33e848c1288806b56040dc0fed86c'
            'f29a1b45c96ee05e64c03181b587f48a5d090839b7356eb4f48fb752a17a899f')

package() {
  install -d "${pkgdir}/usr/share/fonts/TTF"
  install -Dm644 "${srcdir}"/fonts/ttf/*.ttf "${pkgdir}/usr/share/fonts/TTF"
  install -Dm644 "${srcdir}/OFL.txt" "${pkgdir}/usr/share/licenses/${pkgname}/OFL.txt"
  install -Dm644 "${srcdir}/FONTLOG.txt" "${pkgdir}/usr/share/doc/${pkgname}/FONTLOG.txt"
  install -Dm644 "${srcdir}/75-ttf-inconsolata.conf" "${pkgdir}/usr/share/fontconfig/conf.avail/75-ttf-inconsolata.conf"
}
