# Maintainer: David Runge <dvzrv@archlinux.org>
_name=test_declarative
pkgname=ruby-test_declarative
pkgver=0.0.6
pkgrel=2
pkgdesc="Simply adds a declarative test method syntax to test/unit"
arch=('any')
url="https://github.com/svenfuchs/test_declarative"
license=('MIT')
depends=('ruby')
makedepends=('git' 'ruby-rdoc')
checkdepends=('ruby-rake' 'ruby-bundler' 'ruby-minitest')
options=(!emptydirs)
# can not build from tarball:
# https://github.com/svenfuchs/test_declarative/issues/19
# commit pointing to v${pkgver} (no signatures)
source=("${_name}::git+https://github.com/svenfuchs/${_name}#commit=d0c26d1e5bcd9880bd4a758ce462eb8fd31e2928")
sha512sums=('SKIP')

prepare() {
  mv -v "${_name}" "${pkgname}-${pkgver}"
  cd ${pkgname}-${pkgver}
  # we don't do version pinning
  sed -r 's|~>|>=|g' -i "${_name}.gemspec" Gemfile
}

build() {
  cd "$pkgname-$pkgver"
  gem build "${_name}.gemspec"
}

check() {
  cd "$pkgname-$pkgver"
  BUNDLE_GEMFILE='Gemfile' rake test
}

package() {
  cd "$pkgname-$pkgver"
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies \
              --no-user-install \
              -i "${pkgdir}/${_gemdir}" \
              -n "${pkgdir}/usr/bin" \
              ${_name}-${pkgver}.gem
  install -vDm 644 MIT-LICENSE \
    "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
  cd "${pkgdir}/${_gemdir}"
  rm -rvf cache gems/${_name}-${pkgver}/{ext,lib/*/*.so} \
    extensions/*/*/${_name}-${pkgver}/{mkmf.log,gem_make.out}
}
