# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=awxkit
_pkgname=awx
pkgver=11.0.0
pkgrel=1
pkgdesc="cli client and python library for ansible awx (tower)"
arch=('any')
url="https://github.com/ansible/awx"
license=('Apache')
depends=('python-six' 'python-yaml' 'python-requests')
makedepends=('python-pip' 'python-setuptools')
options=(!emptydirs)
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/ansible/${_pkgname}/archive/${pkgver}.tar.gz")
sha512sums=('2368a8774f953c53ceabfd1cb298aec7148c9569cfd0b792f16aa40a2a1b9152906c6107fda6bd13f86e6b1d6830267be2d39b7f2b21206727dda0c092607e80')

build() {
    cd "${_pkgname}-${pkgver}/${pkgname}"
    python setup.py build
}

package() {
    cd "${_pkgname}-${pkgver}/${pkgname}"
    python setup.py install --root="$pkgdir/" --optimize=1
}
