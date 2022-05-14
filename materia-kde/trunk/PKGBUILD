# Maintainer: Bruno Pagani <archange@archlinux.org>

pkgbase=materia-kde
pkgname=(materia-kde kvantum-theme-materia)
pkgver=20220510
pkgrel=1
pkgdesc="Materia theme for KDE Plasma 5"
arch=(any)
url="https://github.com/PapirusDevelopmentTeam/materia-kde"
license=(GPL3)
options=(!strip)
source=(${url}/archive/${pkgver}/${pkgbase}-${pkgver}.tar.gz)
sha256sums=('5063e3e36da73c4df1b3f299513421f9d344733b0ce863da58f2db46c4f208a8')

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
