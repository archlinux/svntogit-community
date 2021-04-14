# Maintainer: David Runge <dvzrv@archlinux.org>

_name=vimrunner
pkgname=ruby-vimrunner
pkgver=0.3.4
pkgrel=2
pkgdesc="Spawn a Vim instance and control it programatically"
arch=('any')
url="https://github.com/AndrewRadev/vimrunner"
license=('MIT')
depends=('ruby' 'gvim')
makedepends=('ruby-bundler' 'ruby-rake' 'ruby-rdoc' 'ruby-rspec')
source=("$pkgname-$pkgver.tar.gz::https://github.com/AndrewRadev/${_name}/archive/v${pkgver}.tar.gz")
sha512sums=('625136d8b7bff60fd286cbf865a07ffbc512733bd350fb2583246f312bbba2859a3e035b1b72d3dbb8617c91bf669351b989a7f69971c09c8516255555ceea65')

prepare() {
  mv -v "${_name}-${pkgver}" "${pkgname}-${pkgver}"
  cd "$pkgname-$pkgver"
  # we don't do version pinning
  sed -r 's|~>|>=|g' -i "${_name}.gemspec" Gemfile
}

build() {
  cd "$pkgname-$pkgver"
  gem build "${_name}.gemspec"
}

package() {
  cd "$pkgname-$pkgver"
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies \
              --no-user-install \
              -i "${pkgdir}/${_gemdir}" \
              -n "${pkgdir}/usr/bin" \
              ${_name}-${pkgver}.gem
  install -vDm 644 LICENSE \
    -t "${pkgdir}/usr/share/licenses/${pkgname}"
  cd "${pkgdir}/${_gemdir}"
  rm -rvf build_info cache extensions gems/${_name}-${pkgver}/{ext,lib/*/*.so}
}
