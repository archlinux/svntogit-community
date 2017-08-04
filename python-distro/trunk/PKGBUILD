# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Tomislav Ivek <tomislav.ivek@gmail.com>

pkgbase=python-distro
pkgname=('python-distro' 'python2-distro')
pkgver=1.0.4
pkgrel=2
pkgdesc='Linux OS platform information API'
url='https://github.com/nir0s/distro'
arch=('any')
license=('Apache')
makedepends=('python-setuptools' 'python-sphinx' 'python2-setuptools' 'python2-sphinx')
checkdepends=('python-pytest' 'python2-pytest')
source=(${pkgbase}-${pkgver}.tar.gz::https://github.com/nir0s/distro/archive/v${pkgver}.tar.gz)
sha256sums=('7a243ffc9d3da77386edf626ae7636d1ac9300b7fdfd886fa3da3470f11e44a7')
sha512sums=('117d44ff8145231e2ad7e2641c87c61d42804b84935a5d694ef4b57cdd220b336a86320c5073d2675cb6064b9285123fbea9601d644f94b4a139b7524e09faa8')

prepare() {
  cp -a distro-${pkgver}{,-py2}

}

build() {
  (cd distro-${pkgver}
    python setup.py build
    make man SPHINXBUILD=sphinx-build
  )
  (cd distro-${pkgver}-py2
    python2 setup.py build
    make man SPHINXBUILD=sphinx-build2
  )
}

check() {
  (cd distro-${pkgver}
    py.test
  )
  (cd distro-${pkgver}-py2
    py.test2
  )
}

package_python-distro() {
  depends=('python' 'python-setuptools')
  cd distro-${pkgver}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 build_docs/man/ld.1 "${pkgdir}/usr/share/man/man1/${pkgname}.1"
  install -Dm 644 README.md CHANGES -t "${pkgdir}/usr/share/doc/${pkgname}"
}

package_python2-distro() {
  depends=('python2' 'python2-setuptools')
  cd distro-${pkgver}-py2
  python2 setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 build_docs/man/ld.1 "${pkgdir}/usr/share/man/man1/${pkgname}.1"
  install -Dm 644 README.md CHANGES -t "${pkgdir}/usr/share/doc/${pkgname}"
  mv "${pkgdir}/usr/bin/distro"{,2}
}

# vim: ts=2 sw=2 et:
