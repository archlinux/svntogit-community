# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Tomislav Ivek <tomislav.ivek@gmail.com>

pkgbase=python-distro
pkgname=('python-distro' 'python2-distro')
pkgver=1.3.0
pkgrel=2
pkgdesc='Linux OS platform information API'
url='https://github.com/nir0s/distro'
arch=('any')
license=('Apache')
makedepends=('python-setuptools' 'python-sphinx'
             'python2-setuptools' 'python2-sphinx')
checkdepends=('python-pytest' 'python2-pytest')
options=('!makeflags')
source=(${pkgbase}-${pkgver}.tar.gz::https://github.com/nir0s/distro/archive/v${pkgver}.tar.gz)
sha256sums=('4c8c92d72839328dfae6ffcbbd0a0eda89d8b74edf29c697a74a6c9f32eb19ae')
sha512sums=('c453e57594d557443a2faa10214bbaad18abc916e8e67971cd7f04627e2b4b4a62a06c267306179d803673b139053feffbed4406cf0284eac6be6a2dfc6830ec')

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
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}

package_python2-distro() {
  depends=('python2' 'python2-setuptools')
  cd distro-${pkgver}-py2
  python2 setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 build_docs/man/ld.1 "${pkgdir}/usr/share/man/man1/${pkgname}.1"
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  mv "${pkgdir}/usr/bin/distro"{,2}
}

# vim: ts=2 sw=2 et:
