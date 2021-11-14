# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor : Drew DeVault <sir@cmpwn.com>

pkgname=samurai
pkgver=1.2
pkgrel=2
pkgdesc="ninja-compatible build tool written in C"
arch=('x86_64')
url="https://github.com/michaelforney/${pkgname}"
license=('ISC' 'Apache' 'MIT')
source=("${pkgname}-${pkgver}.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha256sums=('37a2d9f35f338c53387eba210bab7e5d8abe033492664984704ad84f91b71bac')
b2sums=('31ec4e728a90bbbba49964487c1c682a8cf3684bf05962dc74a73f51a9e3b539e1b8044b24001c748cd75de51f91850671342d87cc3d27f03b5f50f857bd5965')

build() {
    cd "${srcdir}"/${pkgname}-${pkgver}

    make samu
}

package() {
    cd "${srcdir}"/${pkgname}-${pkgver}

    make install PREFIX=/usr DESTDIR="${pkgdir}"
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
