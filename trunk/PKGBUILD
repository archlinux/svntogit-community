# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=awxkit
_pkgname=awx
pkgver=14.0.0
pkgrel=1
pkgdesc="cli client and python library for ansible awx (tower)"
arch=('any')
url="https://github.com/ansible/awx"
license=('Apache')
depends=('python-six' 'python-yaml' 'python-requests')
makedepends=('python-pip' 'python-setuptools')
options=(!emptydirs)
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/ansible/${_pkgname}/archive/${pkgver}.tar.gz")
sha512sums=('989457d28b397c19139582f82f63ac75d855736c0a53ad88e9040d24b9f9d0cc5692ba173af18d33552248d7ef9bbc7e056e1e8e430b9bef7d1e9be812f53772')

build() {
    cd "${_pkgname}-${pkgver}/${pkgname}"
    python setup.py build
}

package() {
    cd "${_pkgname}-${pkgver}/${pkgname}"
    python setup.py install --root="$pkgdir/" --optimize=1
}
