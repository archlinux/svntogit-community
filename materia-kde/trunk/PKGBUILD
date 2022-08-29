# Maintainer:
# Comtributor: Bruno Pagani <archange@archlinux.org>

pkgbase=materia-kde
pkgname=(materia-kde kvantum-theme-materia)
pkgver=20220823
pkgrel=1
pkgdesc="Materia theme for KDE Plasma 5"
arch=(any)
url="https://github.com/PapirusDevelopmentTeam/materia-kde"
license=(GPL3)
options=(!strip)
source=(${url}/archive/${pkgver}/${pkgbase}-${pkgver}.tar.gz)
sha256sums=('2731ffbf22e6fa4afa321fd677d3981c9a3851b9bca1e65d2439e6f3f6b735bf')

package_materia-kde() {
    optdepends=('materia-gtk-theme: Matching GTK theme'
                'kvantum-theme-materia: Materia theme for Kvantum Qt style (recommended)')

    cd ${pkgbase}-${pkgver}
    install -d "${pkgdir}"/usr/share

    cp -r plasma "${pkgdir}"/usr/share
    cp -r aurorae "${pkgdir}"/usr/share
    cp -r color-schemes "${pkgdir}"/usr/share
    cp -r sddm "${pkgdir}"/usr/share
    cp -r konsole "${pkgdir}"/usr/share
    cp -r yakuake "${pkgdir}"/usr/share
}

package_kvantum-theme-materia() {
    pkgdesc="Materia theme for KDE Plasma 5"
    depends=(kvantum-qt5)

    cd ${pkgbase}-${pkgver}
    install -d "${pkgdir}"/usr/share

    cp -r Kvantum "${pkgdir}"/usr/share
}
